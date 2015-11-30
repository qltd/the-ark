(function ($) {

  function toggleUpcomingEventsText (action) {
    return 'Click to ' + action + ' More Upcoming Events';
  }

  Drupal.behaviors.theArkEventsUpcoming = {
    attach: function () {
      var container = $('.events-upcoming-view')
        , events = $('.calendar-column').not('.first');
      if (container.length === 0 || events.length === 0) return;

      var toggleContainer = $('<div class="show-upcoming-toggle-container"></div>')
        , toggle = $('<a class="show-upcoming-toggle" role="button"></div>');

      toggle.text(toggleUpcomingEventsText('Show'));
      toggleContainer.append(toggle);
      container.append(toggleContainer);
      events.addClass('upcoming-hidden');

      toggle.on('tap', function () {
        if (events.hasClass('upcoming-hidden')) {
          events.removeClass('upcoming-hidden');
          toggle.text(toggleUpcomingEventsText('Hide'));
        } else {
          events.addClass('upcoming-hidden');
          toggle.text(toggleUpcomingEventsText('Show'));
        }
      });
    }
  };
})(jQuery);
