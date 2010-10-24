<?php
// $Id: context_reaction_theme.inc,v 1.1.2.3 2010/08/09 15:13:03 yhahn Exp $

/**
 * Expose themes as context reactions.
 */
class context_reaction_page_title extends context_reaction_theme {
  /**
   * Allow admins to provide a section title, section subtitle and section class.
   */
  function options_form($context) {
    $form = parent::options_form($context);
    $values = $this->fetch_from_context($context);
        
    $form['page_title'] = array(
      '#title' => t('Page title'),
      '#description' => t('Provides the page title.'),
      '#type' => 'textfield',
      '#maxlength' => 255,
      '#default_value' => isset($values['page_title']) ? $values['page_title'] : '',
    );
    
    return $form;
  }

  /**
   * Set 'head_title'
   */
  function execute(&$vars) {
    parent::execute($vars);
    
    foreach ($this->get_contexts() as $k => $v) {
      if (!empty($v->reactions[$this->plugin]['page_title'])) {
        $vars['head_title'] = t($v->reactions[$this->plugin]['page_title']);
      }
    }
  }
}
